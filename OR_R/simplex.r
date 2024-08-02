# Simplex

# max z = 4x1 + 10x2
# stc,
# 2x1 + x2 <= 50 ,
# 2x1 + 5x2 <= 100 ,
# 2x1 + 5x2 <=90 , x1,x1>=0


library(boot)

obj_fn=c(4,10)
f1c=c(2,1)
f2c=c(2,5)
f3c=c(2,5)

c1=50
c2=100
c3=90

simplex(a=obj_fn,A1=rbind(f1c,f2c,f3c),b1=c(c1,c2,c3),maxi=T)