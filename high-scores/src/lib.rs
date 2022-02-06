#[derive(Debug)]
pub struct HighScores<'a> {
    list: &'a [u32], 
}

impl<'a> HighScores<'a> {
    pub fn new(scores: &'a [u32]) -> Self {
        Self {
            list: scores
        }
    }
    
    /// Return all the scores.
    pub fn scores(&self) -> &[u32]  {
        self.list
    }
    
    /// Grab the last number from the slice.
    ///
    /// # Example
    ///
    /// ```
    /// use high_scores::HighScores;
    /// let high_scores = HighScores::new(&[]);
    /// assert_eq!(high_scores.latest(), None);
    /// ```
    pub fn latest(&self) -> Option<u32> {
        match self.list.last() {
            Some(last) => Some(*last), 
            None => None, 
        }
    }
    
    /// Find the biggest number a slice.
    ///
    /// # Example
    ///
    /// ```
    /// use high_scores::HighScores;
    /// let high_scores = HighScores::new(&[40, 100, 70]);
    /// assert_eq!(high_scores.personal_best(), Some(100));
    /// ```
    pub fn personal_best(&self) -> Option<u32> {
        match self.list.iter().max() {
            Some(biggest_number) => Some(*biggest_number), 
            None => None, 
        }
    }
    
    /// Sort the slice and remove smallest numbers. 
    ///
    /// # Example
    ///
    /// ```
    /// use high_scores::HighScores;
    /// let high_scores = HighScores::new(&[10, 30, 90, 30, 100, 20, 10, 0, 30, 40, 40, 70, 70]);
    /// assert_eq!(high_scores.personal_top_three(), vec![100, 90, 70]);
    /// ```
    pub fn personal_top_three(&self) -> Vec<u32> {
        let mut list_vec = self.list.to_vec();
        list_vec.sort_by(|a, b| b.cmp(a));
        if list_vec.len() > 3 {
            return list_vec[..3].to_vec();
        } else {
            return list_vec;
        }
    }
}
