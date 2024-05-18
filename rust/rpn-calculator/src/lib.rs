#[derive(Debug)]
pub enum CalculatorInput {
    Add,
    Subtract,
    Multiply,
    Divide,
    Value(i32),
}

pub fn evaluate(inputs: &[CalculatorInput]) -> Option<i32> {
    let mut stack = vec![];
    
    let mut sum = 0;
    for input in inputs.into_iter() {
        match input {
            CalculatorInput::Add => {
                while !stack.is_empty() {
                    sum += stack.pop().unwrap();
                }
                dbg!(sum);
                stack.push(sum)
            },
            CalculatorInput::Subtract => {
                while !stack.is_empty() {
                    sum = stack.pop().unwrap() - sum;
                }
                dbg!(sum);
                stack.push(sum)
            },
            CalculatorInput::Multiply => {
                sum = 1;
                while !stack.is_empty() {
                    sum *= stack.pop().unwrap();
                }
                dbg!(sum);
                stack.push(sum)
            },
            CalculatorInput::Divide => {
                sum = 1;
                while !stack.is_empty() {
                    sum = stack.pop().unwrap() / sum;
                }
                dbg!(sum);
                stack.push(sum)
            },
            CalculatorInput::Value(number) => stack.push(number.to_owned()),
        }
    }
    
    if stack.len() == 1 {
        sum = stack.pop().unwrap();
    }

    Some(sum)
}


