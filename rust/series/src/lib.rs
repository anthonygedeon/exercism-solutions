/// Return a overlapping sublist of elements that can be specified with a size of len.
///
/// # Example
///
/// ```
/// use series::series;
/// let expected: Vec<String> = vec![
///     "20".to_string(), 
///     "02".to_string(), 
///     "22".to_string(), 
/// ];
/// assert_eq!(series("2022", 2), expected);
/// ```
pub fn series(digits: &str, len: usize) -> Vec<String> {
    let mut sublist = vec![]; 
    (0..digits.len()+1)
        .enumerate()
        .for_each(|(i, _)| {
            let ahead = i+len;
            if ahead > digits.len() { return }
            let group = digits[i..ahead].to_string();
            sublist.push(group);
        });
    sublist
}
