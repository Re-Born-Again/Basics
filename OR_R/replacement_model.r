# Replacement Model

# initial cost : 6100
# scrap value : 100
# maintenance cost : 100,250,400,600,900,1200,1600,2000

initial_cost = 6100
scrap_value = 100
maintenance_cost = c(100,250,400,600,900,1200,1600,2000)

total_cost = initial_cost - scrap_value + cumsum(maintenance_cost)
avg_cost = total_cost / (1:length(total_cost))
optimal_year = which.min(avg_cost)

cat("Optimal year : ",optimal_year,"\n")
cat("Optimal cost : ",avg_cost[optimal_year])