/// Return the Hamming distance between the strings,
/// or None if the lengths are mismatched.
pub fn hamming_distance(s1: &str, s2: &str) -> Option<usize> {
    if s1.len() != s2.len() { return None; }
    
    let hamming_distance = s1.chars()
        .zip(s2.chars())
        .filter(|(nucletide_a, nucletide_b)| nucletide_a != nucletide_b)
        .count();

    Some(hamming_distance) 
}
