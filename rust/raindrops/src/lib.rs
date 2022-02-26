pub fn raindrops(n: u32) -> String {
    let mut raindrop = String::new();
    let factor = |num| n % num == 0;

    if factor(3) {
        raindrop.push_str("Pling");
    }
    if factor(5) {
        raindrop.push_str("Plang");
    }
    if factor(7) {
        raindrop.push_str("Plong");
    }

    if raindrop.is_empty() {
        return n.to_string();
    }

    return raindrop;
}
