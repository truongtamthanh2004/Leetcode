/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func findGCD(a int, b int) int {
    for a != b {
        if a > b {
            a -= b
        } else if b > a {
            b -= a
        }
    }
    return a
 }
func insertGreatestCommonDivisors(head *ListNode) *ListNode {
    current := head

    for current != nil && current.Next != nil {
        gcd := findGCD(current.Val, current.Next.Val)
        newNode := new(ListNode)
        newNode.Val = gcd
        newNode.Next = current.Next
        current.Next = newNode

        current = newNode.Next
    }

    return head
}