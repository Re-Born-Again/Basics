# Queueing Model - 1

# arrival of 10 cars per hour
# service time of 3 mins

# another qn
# inter arrival time : 12 mins
# mean service rate : 4 mins

lambda=1/6
mu=1/3

rho=lambda/mu
ls=rho/(1-rho)
lq=(rho^2)/(1-rho)
ws=ls/lambda
wq=lq/lambda

cat("Traffic Intensity : ",rho,"\n")
cat("Avg. no. customers in system : ",ls,"\n")
cat("Avg. no. customers in queue : ",lq,"\n")
cat("Avg. time spent in system : ",ws,"\n")
cat("Avg. time spent in queue : ",wq,"\n")