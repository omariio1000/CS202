public class Lab8 {
	
	private Lab8() {
		LLL list = new LLL();
		list.build(15);
		list.display();
		int matches = list.findMatches(list.findLast());
		System.out.println("Number of matches: " + matches);
		list.deleteFirstlast();
		list.display();
		System.out.println("REMAINING: ");
		list.removeExcept();
		list.display();
		LLL newList = new LLL();
		newList.copyList(list);
		System.out.println("New List:");
		newList.display();
		
	}
	
	public static void main(String[] args) {
		new Lab8();
	}
}

class node {
	public node() {
		this.data = 0;
		this.next = null;
	}

	public node(int data) {
		this.data = data;
		this.next = null;
	}

	public node getNext() {
		return next;
	}

	public void setNext(node obj) {
		this.next = obj;
	}

	public int getData() {
		return this.data;
	}

	public void setData(int obj) {
		this.data = obj;
	}
	
	public void display() {
		System.out.println(this.data);
	}

	public node next;
	protected int data;
}

class LLL {
	public LLL() {
		this.head = null;
	}
	
	public void insertData(int data) {
		if (this.head == null) {
			this.head = new node(data);
			return;
		}
		this.head = insertData(head, data);
		return;
	}
	
	public node insertData(node head, int data) {
		if (head == null) {
			head = new node(data);
			return head;
		}
		head.setNext(insertData(head.getNext(), data));
		return head;
	}
	
	
	public void display() {
		if (head == null) return;
		display(head);
		return;
	}
	
	public void display(node head) {
		if (head == null) return;
		head.display();
		display(head.getNext());
		return;
	}
	
	public void build(int num) {
		for (int i = 0; i < num; i++) {
			insertData((int) (Math.random() * 101));
		}
	}
	
	public int findLast() {
		if (this.head == null) return -999;
		return findLast(this.head);
	}
	
	public int findLast(node head) {
		if (head.getNext() == null) return head.getData();
		return findLast(head.getNext());
	}
	
	public int findMatches(int num) {
		if (this.head == null) return 0;
		return findMatches(this.head, num);
	}
	
	public int findMatches(node head, int num) {
		if (head == null) return 0;
		if (head.getData() == num) return 1 + findMatches(head.getNext(), num);
		return findMatches(head.getNext(), num);
	}
	
	public void deleteFirstlast() {
		if (this.head == null) return;
		this.head = this.head.getNext();
		if (this.head.getNext() == null) {
			head.setNext(null);
			return;
		}
		deleteLast(this.head);
	}
	
	public node deleteLast(node head) {
		if (head.getNext().getNext() == null) {
			//System.out.println("LAST: " + head.getNext().getData());
			head.setNext(null);;
			return head;
		}
		head = deleteLast(head.getNext());
		return head;
	}
	
	public void removeExcept() {
		if (head == null) return;
		if (head.getNext() == null) return;
		this.head = removeExcept(this.head);
		return;
	}
	
	public node removeExcept(node head) {
		if (head.getNext().getNext() == null) return head;
		head = removeExcept(head.getNext());
		return head;
	}
	
	public void copyList(LLL copying) {
		if (copying == null || copying.head == null) return;
		this.head = copyList(this.head, copying.head);
		return;
	}
	
	public node copyList(node dest, node source) {
		if (source == null) return null;
		dest = new node(source.getData());
		dest.setNext(copyList(dest.getNext(), source.getNext()));
		return dest;
	}
	
	public node head;
}