pub use std::collections::HashMap;

/// Implements the hashamp API as a macro.
#[macro_export]
macro_rules! hashmap {
    ($($k:expr => $v:expr),+ $(,)?) => {{
        let mut map = $crate::HashMap::new();
        $( map.insert($k, $v); )+
        map
    }};
    () => { $crate::HashMap::new() }
}
