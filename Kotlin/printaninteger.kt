import java.util.Scanner

fun main(args: Array<String>) {

    val readnum = Scanner(System.`in`)
    print("Enter a number: ")

    var integer:Int = readnum.nextInt()

    println("You entered: $integer")
}