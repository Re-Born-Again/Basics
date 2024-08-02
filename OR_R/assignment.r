# Assignment problem

# Assignment matrix :
# 11 24 6
# 8  10 11
# 9  6  7

library(lpSolve)

mat=matrix(c(11,24,6,8,10,11,9,6,7),nrow=3,ncol=3,byrow=T)
cat("Asignment matrix : \n")
print(mat)
cost=lp.assign(mat)
print(cost$solution)