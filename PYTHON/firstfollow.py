EPSILON = "Ɛ"
END_MARKER = "$"

ProductionsT = dict[str, list[str]]
FirstFollowT = dict[str, set[str]]

productions: ProductionsT = {}
first: FirstFollowT = {}
follow: FirstFollowT = {}

def compute_first(var):
    # If FIRST set is already computed, return it
    if var in first:
        return first[var]

    first_set = set()

    # If var is a terminal or ε, its FIRST set is itself
    if not var.isupper() or var == EPSILON:
        return {var}

    # Iterate over each production for the variable
    for production in productions[var]:
        for symbol in production:
            # Compute FIRST of the current symbol
            symbol_first = compute_first(symbol)
            first_set.update(symbol_first - {EPSILON})

            # If ε is not in FIRST(symbol), stop
            if EPSILON not in symbol_first:
                break
        else:
            # If ε is in FIRST of all symbols in production, add ε to FIRST(var)
            first_set.add(EPSILON)

    # Store the computed FIRST set
    first[var] = first_set
    return first_set


def compute_follow(var, is_start=False):
    if var in follow:
        return follow[var]

    follow_set = set()
    follow[var] = follow_set  # Store an empty set to prevent infinite recursion

    if is_start:
        follow_set.add(END_MARKER)

    for head, bodies in productions.items():
        for body in bodies:
            for i, symbol in enumerate(body):
                if symbol == var:
                    # Case 1: If `var` is not the last symbol, add FIRST of the next symbol
                    if i + 1 < len(body):
                        beta = body[i + 1]
                        beta_first = compute_first(beta)
                        follow_set.update(beta_first - {EPSILON})
                        # If FIRST(beta) contains EPSILON, add FOLLOW(head)
                        if EPSILON in beta_first:
                            follow_set.update(compute_follow(head))
                    # Case 2: If `var` is the last symbol, add FOLLOW(head)
                    if i + 1 == len(body):
                        follow_set.update(compute_follow(head))

    follow[var] = follow_set
    return follow_set


def parse_file(fname: str) -> ProductionsT:
    productions: ProductionsT = {}
    with open(fname, encoding="utf-8") as f:
        for line in f:
            head, rules = line.split("->")
            body = [s.strip() for s in rules.split("|")]
            head = head.strip()
            if head in productions:
                productions[head].extend(body)
            else:
                productions[head] = body

    return productions


fname = "ip.txt"
productions = parse_file(fname)

for var in productions:
    first[var] = compute_first(var)
for i, var in enumerate(productions):
    follow[var] = compute_follow(var, i == 0)

print(productions)

print("FIRST\n")
for var, first_var in first.items():
    print(f"FIRST({var}) = {first_var}")
print("\nFOLLOW\n")
for var, follow_var in follow.items():
    print(f"FOLLOW({var}) = {follow_var}")