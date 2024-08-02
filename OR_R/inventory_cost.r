# Inventory cost

# annual demand : 200
# inventory cost : 1
# holding cost : 25

an_dem = 200
inv_cost = 1
hol_cost = 25

eoq = sqrt((2*an_dem*inv_cost)/hol_cost)
time_bt = eoq / an_dem
ord_per_yr = an_dem / eoq
c_min = sqrt(2*an_dem*inv_cost*hol_cost)
tot_cost = c_min + an_dem

cat("Economic Order Quantity : ",eoq,"\n")
cat("Time between two consecutive purchases : ",time_bt,"\n")
cat("Orders per year : ",ord_per_yr,"\n")
cat("Minimum average yearlt cost : ",c_min,"\n")
cat("Total cost : ",tot_cost,"\n")