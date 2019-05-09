def distance(s1, s2):
    if len(s1) != len(s2):
        raise ValueError("Sequences must be of equal length!") 
        
    return sum(p1 != p2 for p1, p2 in zip(s1, s2))