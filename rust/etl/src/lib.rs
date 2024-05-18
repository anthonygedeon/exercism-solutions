#![deny(missing_docs)]
//! Performs ETL - Extraction - Transform - Load on legacy scrabble score data structure 
//! We're going to extract some Scrabble scores from a legacy system.
//! The old system stored a list of letters per score:
//!
//! 1 point: "A", "E", "I", "O", "U", "L", "N", "R", "S", "T", <br>
//! 2 points: "D", "G", <br>
//! 3 points: "B", "C", "M", "P", <br>
//! 4 points: "F", "H", "V", "W", "Y", <br>
//! 5 points: "K", <br>
//! 8 points: "J", "X", <br>
//! 10 points: "Q", "Z",
//!
//! The new Scrabble system instead stores the score per letter in lowercase.
//!
//! "a" is worth 1 point. <br>
//! "b" is worth 3 points. <br>
//! "c" is worth 3 points. <br>
//! "d" is worth 2 points. 

use std::collections::BTreeMap;

/// Return a new data structure that assigns each character their given point.
/// 
/// # Example
/// 
/// ```rust
/// use std::collections::BTreeMap;
/// use etl::transform;
///
/// fn input_from(v: &[(i32, Vec<char>)]) -> BTreeMap<i32, Vec<char>> {
///     v.iter().cloned().collect()
/// }
/// 
/// fn expected_from(v: &[(char, i32)]) -> BTreeMap<char, i32> {
///    v.iter().cloned().collect()
/// }
///
/// let input = input_from(&[(1, vec!['A', 'E', 'I', 'O', 'U'])]);
/// let expected = expected_from(&[('a', 1), ('e', 1), ('i', 1), ('o', 1), ('u', 1)]);
/// assert_eq!(expected, etl::transform(&input));
/// ```
///
pub fn transform(h: &BTreeMap<i32, Vec<char>>) -> BTreeMap<char, i32> {
    let mut scores: BTreeMap<char, i32> = BTreeMap::new();
    
    // h implements the IntoIterator trait so no need to append `.iter()`
    for (&point, letters) in h {
        for letter in letters {
            // point is automatically dereferenced by prefixing it with & since i32 implements the Copy trait
            scores.insert(letter.to_ascii_lowercase(), point);
        }
    }

    scores
}
