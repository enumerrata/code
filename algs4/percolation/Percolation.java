import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;



public class Percolation {
	private int N;
	private boolean[] grid;
	private WeightedQuickUnionUF uf;
	private WeightedQuickUnionUF uf1;
	private int size;
	

	public Percolation(int N)              // create N-by-N grid, with all sites blocked
	{
        if (N <= 0)
            throw new IllegalArgumentException("Argument out of bound");

		this.N = N;
		size = N * N;
		uf = new WeightedQuickUnionUF(size + 2); // top/bottom
		uf1 = new WeightedQuickUnionUF(size + 1); 
		grid = new boolean[size];

        for (int k = 0; k < N; k++) {
            uf.union(size, k);                     //connect first row to the virtual top
            uf1.union(size, k);
            uf.union(size + 1, size - N + k);   //connect bottom row to the virtual bottom
        }

	}

    private void indexValid(int i, int j) {
        if (i <= 0 || i > N)
            throw new IndexOutOfBoundsException("row i out of bound.");
        if (j <= 0 || j > N)
            throw new IndexOutOfBoundsException("column j out of bound.");
    }

    private int xyTo1D(int i, int j) {
        indexValid(i, j);
        return (i - 1) * N + j - 1;                         //convert the coordinate to 1D index
    }


	public void open(int i, int j)         // open site (row i, column j) if it is not already
	{
		int index = xyTo1D(i, j);

		if (!grid[index])
			grid[index] = true;          //open the grid if it is not already open

		if (i != 1 && isOpen(i - 1, j)) {  //union the open left grid if any
			uf.union(xyTo1D(i - 1, j), index);
			uf1.union(xyTo1D(i - 1, j), index);
		}

		if (i != N && isOpen(i + 1, j)) {  //union the open right grid if any
			uf.union(xyTo1D(i + 1,j), index);
			uf1.union(xyTo1D(i + 1, j), index);
		}

		if (j != 1 && isOpen(i, j - 1)) {  //union the open upper grid if any
			uf.union(xyTo1D(i, j - 1), index);
			uf1.union(xyTo1D(i, j - 1), index);
		}

		if (j != N && isOpen(i, j + 1)) {  //union the open lower grid if any
			uf.union(xyTo1D(i, j + 1), index);
			uf1.union(xyTo1D(i, j + 1), index);
		}
	}

	public boolean isOpen(int i, int j)    // is site (row i, column j) open?
	{
		return grid[xyTo1D(i,j)];
	}

	public boolean isFull(int i, int j)    // is site (row i, column j) full?
	{
        int index = xyTo1D(i, j);
        return (isOpen(i, j) && uf.connected(size, index) && uf1.connected(size, index));
//isFull is only true when the site is open and connected to virtual top both
//with and without the existence of virtual bottom.
	}

	public boolean percolates()            // does the system percolate?
	{
        if (N == 1 && isOpen(1, 1) == false) return false;

        return uf.connected(size, size + 1);
    }
}



