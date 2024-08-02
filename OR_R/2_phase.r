# 2-Phase

# max z = 3x1 - x2
# stc,
# 2x1 + x2 >= 2 ,
# x1 + 3x2 <= 2 ,
# x1 <= 4 , x1,x1>=0

library(lpSolve)

obj<-c(3,-1)
mat<-matrix(c(2,1,
            1,3,
            0,1),ncol=2,byrow=TRUE)
right<-c(2,2,4)
dir<-c(">=","<=","<=")

num_artificial<-ncol(mat)
c_phase1<-c(rep(0,length(obj)),rep(1,num_artificial))

result_phase1<-lp("min",c_phase1,mat,dir,right)

if(result_phase1$status!=0||any(is.na(result_phase1$solution))){
    cat("No feasbile solution found is Phase 1.\n")

}else{
    cat("Feasible solution found in Phase 1.\n")
}

result_phase2<-lp("max",obj,mat,dir,right)

if(result_phase2$status!=0||any(is.na(result_phase2$solution))){
    cat("No feasible soltion found in Phase 2.\n")
}else{
    cat("Optimal solution found in Phase 2.\n")
    cat("\nFinal solution\n")
    cat("objective value:",result_phase2$objval,"\n")
    cat("optimal values of variables:",result_phase2$solution[1:length(obj)],"\n")
}