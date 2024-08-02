# Big-M

# max z = 6x1 + 4x2
# stc,
# 2x1 + 3x2 <= 30 ,
# 3x1 + 2x2 <= 24 ,
# x1 + x2 >= 3 , x1,x1>=0

library(lpSolve)
M<-1000
obj<-c(6,4,0,0,-M)

mat<-matrix(c(2,3,1,0,0,
              3,2,0,1,0,
              1,1,0,0,1),ncol=5,byrow=TRUE)

direction<-c("<=","<=",">=")

rhs<-c(30,24,3)

lp_solution<-lp("max",obj,mat,direction,rhs)

cat("Optimal solution:\n")
cat("x1:",lp_solution$solution[1],"\n")
cat("x2:",lp_solution$solution[2],"\n")
cat("Maximum cost:",lp_solution$objval,"\n")