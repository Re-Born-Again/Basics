# Transportation problem

# Cost matrix : (min)
#                  supply
#     14 56 48 27   70
#     82 35 21 81   47
#     99 31 71 63   93
# dem 70 35 45 60
library(lpSolve)

mat=matrix(c(14,56,48,27,82,35,21,81,99,31,71,63),nrow=3,ncol=4,byrow = T)
supp=c(70,47,93)
dem=c(70,35,45,60)
supp_sign=rep("<=",3)
dem_sign=rep(">=",4)

lpsol=lp.transport(mat,"min",supp_sign,supp,dem_sign,dem)

print("optimal matrix : ")
print(lpsol$solution)
cat("Total cost : ",lpsol$objval)