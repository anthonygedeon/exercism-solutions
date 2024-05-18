use std::collections::HashSet;

pub fn find(sum: u32) -> HashSet<[u32; 3]> {
    let mut triplet = HashSet::new();

    for a in 3..(sum / 2) {
        for b in a..(sum / 2) {
            let c = ((a.pow(2) + b.pow(2)) as f32).sqrt().round() as u32;
            if is_pythagorean_triplet(a, b, c, sum) && is_pythagorean(a, b, c) && c < sum {
                triplet.insert([a, b, c]);
            }
        }
    }

    triplet
}

fn is_pythagorean(a: u32, b: u32, c: u32) -> bool {
    (a.pow(2) + b.pow(2)) == c.pow(2)
}

fn is_pythagorean_triplet(a: u32, b: u32, c: u32, sum: u32) -> bool {
    (a + b + c) == sum
}
