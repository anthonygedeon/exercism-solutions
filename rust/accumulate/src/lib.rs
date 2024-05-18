pub fn map<F, T, R>(input: Vec<T>, mut func: F) -> Vec<R>
where
    F: FnMut(T) -> R,
{
    let mut result = vec![];
    for n in input {
        result.push(func(n));
    }
    result
}
