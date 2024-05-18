pub fn encode(source: &str) -> String {
    let mut result = String::new();
    
    let mut acc = 1;
    let mut prev = 0;
    for i in 1..=source.len() {
       let curr = i;
       if source.chars().nth(prev) == source.chars().nth(curr) {
            acc += 1;
       } else {
           // ignore acc if acc eq 1
           if acc != 1 {
            result.push_str(acc.to_string().as_str());
           }
           result.push(source.chars().nth(prev).unwrap());
           acc = 1;
           prev = curr;
       }
    }
    
    println!("{}", result);
    result
}

pub fn decode(source: &str) -> String {
    let mut result = String::new();

    let mut nums = String::new();
    for (i, c) in source.chars().enumerate() {
        if source.chars().nth(i).unwrap().is_digit(10) {
            nums.push(c);
        } else if source.chars().nth(i).unwrap().is_ascii_alphabetic() || source.chars().nth(i).unwrap().is_whitespace() {
            let repeat_num = nums.parse().unwrap_or(1);
            result.push_str(c.to_string().repeat(repeat_num).as_str());
            nums.clear();
        }
        
    }

    result
}
