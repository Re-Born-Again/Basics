# Sensitivity analysis - cost coef

library(lpSolve)

solve_lp = function(obj,mat,direction,rhs){
    lp_solution <- lp("max",obj,mat,direction,rhs)
    if(lp_solution$status == 0){
        cat("Optimal solution : \n")
        cat("x1 : ",lp_solution$solution[1],"\n")
        cat("x2 : ",lp_solution$solution[2],"\n")
        cat("x3 : ",lp_solution$solution[3],"\n")
        cat("x4 : ",lp_solution$solution[4],"\n")
        cat("Maximum cost : ",lp_solution$objval,"\n")
        cat("(sensitivity analysis for Rhs)")

        for(i in 1:length(rhs)){
            cat("Constraint",i,":",lp_solution$pi[i],"\n")
        }

        cat("Reduced Costs (sensitivity analysis for objective function coefficients):\n")

        for(j in 1:length(obj)){
            cat("Coefficient",j,":",lp_solution$rc[j],"\n")
        }
    }
    else if (lp_solution$status == 2){
        cat("The problem is infeasible.\n")
    }
    else{
        cat("Error in solving the linear programming problem.\n")
    }
    return(lp_solution)
}

original_solution <-solve_lp(obj,mat,direction,rhs)

obj<-c(4,6,2,0,0)
mat <-matrix(c(1,1,1,1,0,
               1,4,7,0,1),ncol = 5,byrow = T)
rhs <-c(3,9)
direction <- c("<=","<=")

original_solution <-solve_lp(obj,mat,direction,rhs)

new_obj_c3 <-c(4,6,12,0,0)
new_solution_c3 <-solve_lp(new_obj_c3,mat,direction,rhs)

cat("Change in maximum value of Z for c3:",new_solution_c3$objval - original_solution$objval,"\n")

new_obj_all <-c(2,8,4,0,0)
new_solution_all <-solve_lp(new_obj_all,mat,direction,rhs)
cat("Change in maximum value of Z for (c1,c2,c3):",new_solution_all$objval - original_solution$objval,"\n")
