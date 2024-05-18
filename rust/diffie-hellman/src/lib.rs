use rand::{thread_rng, Rng};

pub fn private_key(p: u64) -> u64 {
    thread_rng().gen_range(2..p)
}

pub fn public_key(p: u64, g: u64, a: u64) -> u64 {
    mod_expo(g, a, p)
}

pub fn secret(p: u64, b_pub: u64, a: u64) -> u64 {
    public_key(p, b_pub, a)
}

// TODO: O(n) Algorithm. Need to optimize
/// The identify: `(a ⋅ b) mod m = [(a mod m) ⋅ (b mod m)] mod m` is to perform memory-effient pow calculations using modular arithmetic
pub fn mod_expo(base: u64, expo: u64, module: u64) -> u64 {
    if module == 1 {
        return 0;
    }
    let mut c = 1;
    for _ in 0..expo {
        c = (base * c) % module;
    }
    c
}
