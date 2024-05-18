use std::collections::HashSet;

#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist<T: PartialEq + std::hash::Hash + std::cmp::Eq>(
    first_list: &[T],
    second_list: &[T],
) -> Comparison {
    let set1 = first_list.iter().collect::<HashSet<_>>();
    let set2 = second_list.iter().collect::<HashSet<_>>();

    let mut cmp = Comparison::Unequal;

    if set1 == set2 {
        cmp = Comparison::Equal
    } else if set1.is_subset(&set2) {
        cmp = Comparison::Sublist;
    } else if set1.is_superset(&set2) {
        cmp = Comparison::Superlist
    }

    cmp
}
