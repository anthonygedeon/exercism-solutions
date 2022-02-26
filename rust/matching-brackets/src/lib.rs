
pub fn brackets_are_balanced(string: &str) -> bool {
    let mut stack = vec![];
    string.chars().for_each(|bracket| {
        match bracket {
            '{' | '[' | '(' => stack.push(bracket), 
            '}' | ']' | ')' if !stack.is_empty() => (),
            _ => unreachable!(), 
        }
    });
    stack.is_empty()
}
