# Graphical method for LPP

# max z = 4x1 + 5x2
# stc,
# 6x1 + 6x2 <= 36 ,
# x1 + 2x2 <= 10 ,
# x1 <= 4 , x1,x1>=0

c1<- function(x) (36 - 6*x)/6
c2<- function(x) (10-x)/2
c3<- function(x) 4

c4<- function(x) 0
c5<- function(x) 0

library(ggplot2)

p = ggplot(data = data.frame(x=0), aes(x=x)) +
  geom_vline(xintercept = 0)+
  geom_hline(yintercept = 0)+
  stat_function(colour ="Red",fun=c1)+
  stat_function(colour = "Green",fun=c2)+
  geom_vline(xintercept = 4,colour = "Blue")+
  scale_x_continuous(breaks=seq(0,10,1),lim=c(0,10))+
  scale_y_continuous(breaks=seq(0,10,1),lim=c(0,10))+
  labs(title= "Optimization Problem",subtitle = "Graphical Method", x= "X1",y="X2")+
  theme_bw()

feasible_region= data.frame(x=c(0,4,4,2,0),y=c(0,0,2,4,5))

p<- p + geom_polygon(
  data = feasible_region,
  aes(x=x,y=y),
  fill="#fedcba") +
  geom_point(
  data=feasible_region,
  aes(x=x,y=y),
  colour="Black"
  )


library(lpSolve)

f.obj <- c(4,5)
f.con <- matrix(c(1,2,6,6,1,0),nrow=3,byrow=TRUE)
f.dir <- c("<=","<=","<=")
f.rhs<- c(10,36,4)

lp_result <-lp("max",f.obj,f.con,f.dir,f.rhs)
solution <- lp_result$solution

p<-p+ geom_point(
  aes(x=solution[1],y=solution[2]),
  color="yellow",
  size=4
  )

print(p)

# solution <- lp_result$solution
# d=data.frame(rbind(solution))
# colnames(d)=c('x','y')
# p<-p+ geom_point(
#   data=d,
#   aes(x=x,y=y),
#   color="yellow",
#   size=4)