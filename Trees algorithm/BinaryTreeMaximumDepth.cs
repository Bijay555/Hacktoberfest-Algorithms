// Max Depth of a binary tree by David O'Riley in C#.

namespace davidoriley
{
    public class TreeNode<T>
    {
        public T val;
        public TreeNode<T> left;
        public TreeNode<T> right;
        public TreeNode(T x) { val = x; }
    }

    public class BinaryTreeMaximumDepth
    {
        /// <summary>
        /// Determine the max depth of a binary tree
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="node">Root node to determine the depth from.</param>
        /// <param name="answer">Optional. Recursively incremented and returned for final answer.</param>
        /// <param name="depth">Optional. Recursively incremented to determine depth.</param>
        /// <returns>Integer of the max depth of the tree.</returns>
        public static int maxDepth<T>(TreeNode<T> node, int answer = 1, int depth = 1)
        {
            if (node == null) return 0;

            answer = Math.Max(answer, depth);
            if (node.left != null) answer = maxDepth(node.left, answer, depth + 1);
            if (node.right != null) answer = maxDepth(node.right, answer, depth + 1);

            return answer;
        }
    }
    
}
