library(igraph)

activities <- c("1-2", "1-3", "2-4", "3-4", "4-5", "3-5")
duration_a <- c(2, 9, 5, 2, 6, 8)
duration_m <- c(5, 12, 14, 5, 6, 17)
duration_b <- c(14, 15, 17, 8, 12, 20)

expected_time <- (duration_a + 4 * duration_m + duration_b) / 6
variance <- ((duration_b - duration_a) / 6)^2
computations <- data.frame(Activities = activities, Expected_Time = expected_time,Variance = variance)

print("Tabulated Computations for Expected Time and Variance:")
print(computations)

activities <- c("1", "2", "3", "4", "5")
edges <- matrix(c(1, 2, 1, 3, 2, 4, 3, 4, 4, 5,3,5),ncol = 2, byrow = TRUE)

edge_durations<-expected_time
g <- graph_from_edgelist(edges, directed = TRUE)

plot(g, layout = layout_nicely(g), vertex.label = activities, vertex.size = 50)
possible_paths <- all_simple_paths(g, from = 1, to = 5)

calculate_path_value <- function(path) {
    total_duration <- 0
    for (i in 1:(length(path) - 1)) {
        edge <- c(path[i], path[i + 1])
        total_duration <- total_duration + edge_durations[which(edges[,1] == edge[1] &edges[,2] == edge[2])]
    }
    return(total_duration)
}

path_values <- sapply(possible_paths, calculate_path_value)

paths_and_values <- data.frame(Path = sapply(possible_paths, function(path)
paste(activities[path], collapse = " -> ")), Value = path_values)

print(paths_and_values)


critical_path_index <- which.max(path_values)
critical_path <- possible_paths[[critical_path_index]]
critical_path_value <- path_values[critical_path_index]
critical_path_readable <- paste(activities[critical_path], collapse = " -> ")

print(paste("Critical Path:", critical_path_readable))
print(paste("Critical Path Value (Duration):", critical_path_value))