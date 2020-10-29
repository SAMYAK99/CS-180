fun main(args: Array<String>) {

    val num = 5
    var i = 1
    var factorial: Long = 1
    while (i <= num) {
        factorial *= i.toLong()
        i++
    }
    println("Factorial of $num = $factorial")
}
