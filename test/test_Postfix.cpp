#include "postfix.h"
#include "Stack.h"

#include <gtest.h>


TEST(List, can_create_list)
{
    ASSERT_NO_THROW(List<int> *a = new List<int>());
}

TEST(List, can_copy_list)
{
	List<int> *a = new List<int>();
	ASSERT_NO_THROW(List<int> *b = new List<int>(*a));
}

TEST(List, can_get_true_first)
{
	List<int> *a = new List<int>();
	EXPECT_EQ(0, a->GetFirst());
}

TEST(List, can_get_first)
{
	List<int> *a = new List<int>();
	a->Push(9);
	Node<int>* tmp = a->GetFirst();
	EXPECT_EQ(tmp->key,9);
}

TEST(List, error_if_not_elem)
{
	List<int> *a = new List<int>();
	ASSERT_ANY_THROW(a->PushAfter(5,6));
}

TEST(List, can_true_seach)
{
	List<int> *a = new List<int>();
	a->Push(4);
	a->Push(2);
	a->Push(3);
	Node<int>* tmp = a->Search(4);
	Node<int>* tmp2 = new Node<int>();
	tmp2->key = 4;
	EXPECT_EQ(tmp2->key, tmp->key);
}

TEST(list, can_true_push_after)
{
	List<int> *a = new List<int>();
	a->Push(5);
	Node<int>* tmp = new Node<int>;
	tmp->key = 7;
	a->PushAfter(5, tmp->key);
	EXPECT_EQ(tmp->key, a->Search(7)->key);
}

TEST(List, can_remuve_elem)
{
	List<int> *a = new List<int>();

	a->Push(5);
	a->Push(346);
	a->Remove(5);
	ASSERT_EQ(346, a->Search(346)->key);
}

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> *s = new Stack<int>() );
}

TEST(Stack, cant_remuve_if_stack_empty)
{
	Stack<int> *a = new Stack<int>();
	ASSERT_ANY_THROW(a->Pop());
}

TEST(Stack, can_copy_stack)
{
	Stack<int> *a = new Stack<int>();
	ASSERT_NO_THROW(Stack<int> *b = new Stack<int>(*a));
}

TEST(Stack, can_true_is_empty_stack)
{
	Stack<int> *a = new Stack<int>();
	ASSERT_EQ(1, a->IsEmpty());
}

TEST(Stack, can_true_is_full_stack)
{
	Stack<int> *a = new Stack<int>();
	ASSERT_EQ(0, a->IsFull());
}

TEST(Stack, can_pop)
{
	Stack<int> *a = new Stack<int>();
	a->Push(123);
	a->Push(11);
	int c = a->Pop();
	EXPECT_EQ(c, 11);
}
