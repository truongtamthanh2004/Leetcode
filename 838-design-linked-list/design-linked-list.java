class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
        this.next = null;
    }
}

class MyLinkedList {
    Node head;
    int size = 0;

    public MyLinkedList() {
        head = new Node(0);
        size = 0;
    }
    
    public int get(int index) {
        int i = 0;
        Node p = head.next;
        while (p != null) {
            if (i == index) return p.val;

            i++;
            p = p.next;
        }

        return -1;
    }
    
    public void addAtHead(int val) {
        Node node = new Node(val);
        node.next = head.next;
        head.next = node;
        size++;
    }
    
    public void addAtTail(int val) {
        Node p = head;

        while (p.next != null) p = p.next;
        p.next = new Node(val);
        size++;
    }
    
    public void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        
        Node p = head;
        for (int i = 0; i < index; i++) {
            p = p.next;
        }

        Node node = new Node(val);
        node.next = p.next;
        p.next = node;
        size++;
    }
    
    public void deleteAtIndex(int index) {
        int i = -1;
        Node p = head;
        while (p != null && p.next != null) {
            if (i++ == index - 1) {
                Node tmp = p.next;
                p.next = tmp.next;
                tmp.next = null;
                size--;
                return;
            }

            p = p.next;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */