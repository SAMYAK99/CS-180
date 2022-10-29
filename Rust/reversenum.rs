fn main() {
    let mut num: i64 = 123456789123456789;
    let mut rev_num: i64 = 0;

    while num > 0 {
        rev_num *= 10;
        rev_num += num%10;
        num /= 10;
    }

    println!("{}", rev_num);
}
