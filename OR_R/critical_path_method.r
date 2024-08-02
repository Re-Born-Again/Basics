library(igraph)

activities <- c("1", "2", "3", "4", "5")
edges <- matrix(c(1, 2, 1, 3, 2, 4, 2, 5, 3, 4, 4, 5),ncol = 2, byrow = TRUE)
edge_durations <- c(8, 4, 10, 2, 5, 3)

g <- graph_from_edgelist(edges, directed = TRUE)
E(g)$duration <- edge_durations

plot(g, layout = layout_nicely(g), vertex.label = activities, vertex.size = 30)
possible_paths <- all_simple_paths(g, from = 1, to = 5)

calculate_path_value <- function(path) {
    total_duration <- 0
    for (i in 1:(length(path) - 1)) {
        edge <- c(path[i], path[i + 1])
        total_duration <- total_duration + edge_durations[which(edges[,1] == edge[1] & edges[,2] == edge[2])]
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