import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;


public class Deque<Item> implements Iterable<Item> {
	private int n;
	private Node first;
	private Node last;

	public Deque() // construct an empty deque
	{
		n = 0;
		first = null;
		last = null;
	}

	public boolean isEmpty() // is the deque empty?
	{
		return first == null;
	}

	public int size() // return the number of items on the deque
	{
		return n;
	}

	public void addFirst(Item item) // add the item to the front
	{
		if (item == null) {
			throw new NullPointerException();
		}

		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.next = oldfirst;

		if (oldfirst == null) {
			last = first;
		} else {
			oldfirst.prev = first;
		}

		n++;
	}

	public void addLast(Item item) // add the item to the end
	{
		if (item == null) {
			throw new NullPointerException();
		}

		Node oldlast = last;
		last = new Node();
		last.item = item;
		last.prev = oldlast;

		if (oldlast == null) {
			first = last;
		} else {
			oldlast.next = last;
		}

		n++;
	}

	public Item removeFirst() // remove and return the item from the front
	{
		if (isEmpty()) {
			throw new NoSuchElementException();
		}

		Item item = first.item;
		first = first.next;

		if (first == null) {
			last = null;
		} else {
			first.prev = null;
		}

		n--;

		return item;
	}

	public Item removeLast() // remove and return the item from the end
	{
		if (isEmpty()) {
			throw new NoSuchElementException();
		}

		Item item = last.item;
		last = last.prev;

		if (last == null) {
			first = null;
		} else {
			last.next = null;
		}

		n--;

		return item;
	}

	public Iterator<Item> iterator() // return an iterator over items in order from front to end
	{
		return new DequeIterator();
	}

	public static void main(String[] args) // unit testing
	{
		Deque<String> deque = new Deque<String>();

		while (!StdIn.isEmpty()) {
			String item = StdIn.readString();

			if (item.equals("+")) {
				item = StdIn.readString();
				deque.addFirst(item);
			} else if (item.equals("++")) {
				item = StdIn.readString();
				deque.addLast(item);
			} else if (item.equals("exit")) {
				break;
			} else if (item.equals("show")) {
				for (String s : deque) {
					StdOut.println(s);
				}
			} else if (item.equals("-")) {
				if (!deque.isEmpty()) {
					StdOut.print(deque.removeFirst() + " ");
				}
			} else if (item.equals("--")) {
				if (!deque.isEmpty()) {
					StdOut.print(deque.removeLast() + " ");
				}
			}
		}

		StdOut.println("(" + deque.size() + " left on deque)");
	}

	private class DequeIterator implements Iterator<Item> {
		private Node current = first;

		public boolean hasNext() {
			return current != null;
		}

		public void remove() {
			throw new UnsupportedOperationException();
		}

		public Item next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}

			Item item = current.item;
			current = current.next;

			return item;
		}
	}

	private class Node {
		private Item item;
		private Node next;
		private Node prev;
	}
}
