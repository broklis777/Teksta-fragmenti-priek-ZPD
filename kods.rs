use std::fs::File; 
use std::io::Read; 
use std::time::{Duration, Instant}; 
 
fn text_to_words(text: &str) -> Vec<String> { 
    let mut all_words = Vec::new(); 
    let mut word = String::new(); 
    for i in text.chars() { 
        if i != ' '{ 
            word.push(i); 
        } else  { 
            all_words.push(word.clone()); 
            word.clear(); 
        } 
    } 
    if !word.is_empty() { 
        all_words.push(word); 
    } 
    return all_words; 
} 
 
fn main() { 
    let mut file = File::open(r"path\to\text\file.txt").unwrap(); 
    let mut text = String::new(); 
    file.read_to_string(&mut text).unwrap(); 
    let now = Instant::now(); 
    let words = text_to_words(&text); 
    let new_now = Instant::now(); 
    let time = new_now.duration_since(now); 
    println!("{:?}", words); 
    println!("Nepieciešamais laiks bija {:?}", time); 
}


// The code was made by myself, with some improvements and help from ChatGPT
