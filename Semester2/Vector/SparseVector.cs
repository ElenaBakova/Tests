using System.Collections.Generic;

namespace Vector
{
    /// <summary>
    /// Sparse vector container
    /// </summary>
    class SparseVector
    {
        /// <summary>
        /// Vector that contains pairs (position, value)
        /// </summary>
        private List<(int, int)> vector;

        /// <summary>
        /// Adds to vector new value if it's not a zero
        /// </summary>
        public void AddToVector(int value)
        {
            if (value != 0)
            {
                int position = vector[vector.Count - 1].Item1;
                vector.Add((position, value));
            }
        }

        /// <summary>
        /// Creates a new vetctor from array
        /// </summary>
        public void MakeSparseVector(int[] array)
        {
            vector = new();
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] != 0)
                {
                    vector.Add((i, array[i]));
                }
            }
        }

        public static List<(int, int)> operator +(SparseVector first, SparseVector second)
        {
            int i = first.vector.Count - 1;
            int j = second.vector.Count - 1;
            List<(int, int)> result = new();
            while (true)
            {
                if (first.vector[i].Item1 == first.vector[j].Item1)
                {
                    
                }
            }
        }

        public bool Empty
            => vector.Count == 0;
    }
}
