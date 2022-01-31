pub fn collatz(mut n: u64) -> Option<u64> {
    let mut i = 0;
    while n != 1 {
        if n % 2 == 0 {
            n = n / 2;
        } else {
            let (n1, of1) = n.overflowing_mul(3);
            let (n2, of2) = n1.overflowing_add(1);
            if of1 || of2 {return None} 
            n = n2;
        }

        if n >= u64::MAX || n == 0 {
            return None;
        }

        match n.checked_add(n) {
            Some(_) => (), 
            None => return None, 
        }
        match n.checked_mul(n) {
            Some(_) => (), 
            None => return None, 
        }
        i += 1;
    }
    Some(i)
}
