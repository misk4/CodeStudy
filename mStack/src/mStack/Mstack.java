package mStack;

import java.util.Scanner;

public class Mstack {

	private int[] stack;
	private int top;
	private int max;

	public Mstack() {
		max = 10;
		stack = new int[max];
		top = -1;
	}

	public void push(int num) {
		if (max <= ++top) {
			int[] newStack = new int[max * 2];
			System.arraycopy(stack, 0, newStack, 0, max);
			max *= 2;
			stack = newStack;
			stack[top] = num;
		} else {
			stack[top] = num;
		}
	}

	public int pop() {
		if (top < 0) {
			return -1;
		} else {
			return stack[top--];
		}
	}

	public int top() {
		if (top < 0) {
			return -1;
		} else {
			return stack[top];
		}
	}

	public int size() {
		return top + 1;
	}

	public int isEmpty() {
		if (top < 0) {
			return 1;
		} else {
			return 0;
		}
	}

	public static void main(String[] args) {

		Mstack stack = new Mstack();
		Scanner input = new Scanner(System.in);
		String command = "";
		
		int commands = Integer.parseInt(input.nextLine());

		while (commands > 0) {
			command = input.nextLine();
			switch (command.substring(0, 2)) {
			case "pu":
				stack.push(Integer.parseInt(command.substring(5)));
				break;
			case "po":
				System.out.println(stack.pop());
				break;
			case "to":
				System.out.println(stack.top());
				break;
			case "em":
				System.out.println(stack.isEmpty());
				break;
			case "si":
				System.out.println(stack.size());
				break;

			}
			--commands;
		}
		
		input.close();
	}

}
