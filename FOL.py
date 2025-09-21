# ---------- Statements Dictionary ----------
statements = {
    "e": {"subject": "She", "predicate": "studied hard", "singular": True},
    "f": {"subject": "She", "predicate": "is extremely bright", "singular": True},
    "g": {"subject": "You", "predicate": "get 100 in the final exam", "singular": True},
    "h": {"subject": "You", "predicate": "earn an A in the class", "singular": True},
    "i": {"subject": "Take", "predicate": "two Advil", "singular": True},
    "j": {"subject": "Take", "predicate": "three Tylenol", "singular": True},
    "k": {"subject": "It", "predicate": "is raining outside", "singular": True},
    "l": {"subject": "It", "predicate": "is already a cloudy day", "singular": True},
}

# ---------- Build Statement ----------
def build_statement(logic):
    logic = logic.replace(" ", "").replace(",", "")
    neg = False

    for ch in logic:
        if ch == "!":
            neg = True
        elif ch == "&":
            print(" and ", end="")
        elif ch == "|":
            print(" or ", end="")
        elif ch == "*":
            print(" if and only if ", end="")
        elif ch == "~":
            print(" implies ", end="")
        elif ch in ["(", ")"]:
            continue
        else:  # আমাদের key (e, f, g...)
            st = statements[ch]
            text = f"{st['subject']} {st['predicate']}"
            if neg:
                text = f"{st['subject']} not {st['predicate']}"
                neg = False
            print(text, end="")
    print(".")

# ---------- Run ----------
# print("1) She studied hard or she is extremely bright")
build_statement("e | f")

# print("\n2) If you get 100 in the final exam then you earn an A in the class")
build_statement("g ~ h")

# print("\n3) Take either 2 Advil or 3 Tylenol")
build_statement("i | j")

# print("\n4) It is raining outside if and only if it is already a cloudy day")
build_statement("k * l")
