#[derive(Debug, PartialEq, Eq)]
pub enum Error {
    SpanTooLong,
    InvalidDigit(char),
}

pub fn lsp(string_digits: &str, span: usize) -> Result<u64, Error> {
    if span == 0 {
        return Ok(1);
    }

    if string_digits.len() < span {
        return Err(Error::SpanTooLong);
    }

    if let Some(c) = string_digits.chars().find(|c| !c.is_digit(10)) {
        return Err(Error::InvalidDigit(c));
    }

    let mut largest_product = 0;
    for series in string_digits.chars().collect::<Vec<char>>().windows(span) {
        let numbers = series
            .iter()
            .map(|c| c.to_digit(10).unwrap() as u64)
            .collect::<Vec<u64>>();

        let product_of_series = numbers.iter().product::<u64>();
        if product_of_series > largest_product {
            largest_product = product_of_series;
        }
    }

    Ok(largest_product)
}
