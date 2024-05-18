/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let code: String = code.trim().split_whitespace().collect();
    if code.len() <= 1 || code.chars().any(|c| !c.is_ascii_digit()) {
        return false;
    }

    let code = code
        .chars()
        .filter(|c| c.is_ascii_digit())
        .collect::<String>();
    
    println!("==================>{code}");
    let values_1 = (0..code.len())
        .rev()
        .skip(1)
        .step_by(2)
        .map(|n| { 
            let card_number = code.chars()
                .nth(n)
                .unwrap()
                .to_string()
                .parse::<u32>()
                .unwrap();
            let sum = card_number * 2;
            if sum > 9 {
                sum - 9
            } else {
                sum
            }
        });
     
    let values_2 = (0..code.len())
        .rev()
        .step_by(2)
        .map(|n| { 
            code.chars()
                .nth(n)
                .unwrap()
                .to_string()
                .parse::<u32>()
                .unwrap()
        });
    
    let checksum: u32 = values_1.chain(values_2).sum();
    
    checksum % 10 == 0
}
