# Duality

# max 3x + 2y
# x + y >= -1
# x + y <= 7
# x + 2y <= 10
# y <= 3

library(lpSolve)

obj.cof <- c(3, 2)
mat <- matrix(c(-1, -1,
                1, 1,
                1, 2,
                0, 1), ncol = 2, byrow = TRUE)
dir <- c("<=", "<=", "<=", "<=")
rhs <- c(1, 7, 10, 3)

primalSolution <- lp("max", obj.cof,mat,dir,rhs)

print(primalSolution)

primalVariables <- primalSolution$solution
print(primalVariables)

dualCoef <- primalVariables

dualMat <- matrix(c(-1, 1, 1, 0,
                    -1, 1, 2, 1), ncol = 4, byrow = TRUE)
dualSolution <- lp("min",rhs,dualMat,c(">=",">="),obj.cof)

print(dualSolution)
cat("Dual variable values")
print(dualSolution$solution)
