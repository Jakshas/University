using System;
using System.Collections;
using System.Collections.Generic;

namespace zadanie2
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTreeNode1<int> root = new BinaryTreeNode1<int>(1)
            {
                left = new BinaryTreeNode1<int>(2)
                {
                    left = new BinaryTreeNode1<int>(4)
                },
                right = new BinaryTreeNode1<int>(3)
            };
            BinaryTreeNode2<int> root1 = new BinaryTreeNode2<int>(1)
            {
                left = new BinaryTreeNode2<int>(2)
                {
                    left = new BinaryTreeNode2<int>(4)
                },
                right = new BinaryTreeNode2<int>(3)
            };
            BinaryTreeNode3<int> root2 = new BinaryTreeNode3<int>(1)
            {
                left = new BinaryTreeNode3<int>(2)
                {
                    left = new BinaryTreeNode3<int>(4)
                },
                right = new BinaryTreeNode3<int>(3)
            };
            foreach (int s in root.DepthTraverse())
            {
                Console.WriteLine(s);
            }
            Console.WriteLine();
            foreach (int s in root.WidthTraverse())
            {
                Console.WriteLine(s);
            }
            Console.WriteLine();
            foreach (int s in root1)
            {
                Console.WriteLine(s);
            }
            Console.WriteLine();
            foreach (int s in root2)
            {
                Console.WriteLine(s);
            }
        }
    }
    public class BinaryTreeNode1<T>
    {
        public BinaryTreeNode1<T> left { get; set; }
        public BinaryTreeNode1<T> right{ get; set; }
        public T val { get; set; }

        public BinaryTreeNode1(T v)
        {
            val = v;
            right = left = null;
        }
        public IEnumerable DepthTraverse()
        {
            yield return val;
            if (left != null)
            {
                foreach (T val in left.DepthTraverse())
                {
                    yield return val;
                }
            }
            if (right != null)
            {
                foreach (T val in right.DepthTraverse())
                {
                    yield return val;
                }
            }
        }
        public IEnumerable WidthTraverse()
        {
            Queue<BinaryTreeNode1<T>> q = new Queue<BinaryTreeNode1<T>>();
            q.Enqueue(this);
            while (q.Count > 0)
            {
                BinaryTreeNode1<T> pom = q.Dequeue();
                yield return pom.val;
                if(pom.left != null)
                {
                    q.Enqueue(pom.left);
                }
                if(pom.right != null)
                {
                    q.Enqueue(pom.right);
                }
            }
        }
    }
    public class BinaryTreeNode2<T> :IEnumerable
    {
        public BinaryTreeNode2<T> left { get; set; }
        public BinaryTreeNode2<T> right { get; set; }
        public T val { get; set; }

        public BinaryTreeNode2(T v)
        {
            val = v;
            right = left = null;
        }

        public BinaryTreeNode2()
        {
        }

        public IEnumerator GetEnumerator()
        {
            return new BinaryTreeNode2Iterator<T>(this);
        }
    }
    public class BinaryTreeNode2Iterator<T> : IEnumerator<T>
    {
        Stack<BinaryTreeNode2<T>> stack = new Stack<BinaryTreeNode2<T>>();
        BinaryTreeNode2<T> start;
        public BinaryTreeNode2Iterator(BinaryTreeNode2<T> a)
        {
            start = new BinaryTreeNode2<T>()
            {
                left = a
            };
            stack.Push(start);
        }
        public T Current => stack.Peek().val;

        object IEnumerator.Current => stack.Peek().val;

        public void Dispose()
        {

        }

        public bool MoveNext()
        {
            BinaryTreeNode2<T> t = stack.Pop();
            if (t.right != null)
                stack.Push(t.right);
            if (t.left != null)
                stack.Push(t.left);
            return stack.Count != 0;
        }

        public void Reset()
        {
            stack.Clear();
            stack.Push(start);
        }
    }
    public class BinaryTreeNode3<T> : IEnumerable
    {
        public BinaryTreeNode3<T> left { get; set; }
        public BinaryTreeNode3<T> right { get; set; }
        public T val { get; set; }

        public BinaryTreeNode3(T v)
        {
            val = v;
            right = left = null;
        }

        public BinaryTreeNode3()
        {
        }

        public IEnumerator GetEnumerator()
        {
            return new BinaryTreeNode3Iterator<T>(this);
        }
    }
    public class BinaryTreeNode3Iterator<T> : IEnumerator<T>
    {
        Queue<BinaryTreeNode3<T>> stack = new Queue<BinaryTreeNode3<T>>();
        BinaryTreeNode3<T> start;
        public BinaryTreeNode3Iterator(BinaryTreeNode3<T> a)
        {
            start = new BinaryTreeNode3<T>()
            {
                left = a
            };
            stack.Enqueue(start);
        }
        public T Current => stack.Peek().val;

        object IEnumerator.Current => stack.Peek().val;

        public void Dispose()
        {

        }

        public bool MoveNext()
        {
            BinaryTreeNode3<T> t = stack.Dequeue();
            if (t.right != null)
                stack.Enqueue(t.right);
            if (t.left != null)
                stack.Enqueue(t.left);
            return stack.Count != 0;
        }

        public void Reset()
        {
            stack.Clear();
            stack.Enqueue(start);
        }
    }
}

