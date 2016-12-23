import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class PercolationStats {
	private double[] thre;

	public PercolationStats(int N, int T)    // perform T independent computational experiments on an N-by-N grid
	{
        thre = new double[T];
        int counter = 0;   //the counter for open sites
        int row, column;

        if (N <= 0 || T <= 0)
            throw new IllegalArgumentException("Argument out of bound");

        for (int t = 0; t < T ; t++) {
            Percolation perc = new Percolation(N);

            while (!perc.percolates()) {
                row = StdRandom.uniform(1,N+1);      //randomly choose a site to open
                column = StdRandom.uniform(1,N+1);
                if (perc.isOpen(row, column))   continue;
                perc.open(row,column);
                counter++;
            }// the site chosen is already open, choose another site. If not open it and increment the counter

            thre[t] = (double) counter/(N*N);        // the threshold for this trial is recorded in the threshold[]
            counter = 0;
        }
	}

	public double mean()                     // sample mean of percolation threshold
	{
		return StdStats.mean(thre);
	}

	public double stddev()                   // sample standard deviation of percolation threshold
	{
		return StdStats.stddev(thre);
	}

	public double confidenceLo()             // returns lower bound of the 95% confidence interval
	{
		return mean() - 1.96*stddev()/Math.sqrt(thre.length);
	}

	public double confidenceHi()             // returns upper bound of the 95% confidence interval
	{
		return mean() + 1.96*stddev()/Math.sqrt(thre.length);
	}

	public static void main(String[] args)   // test client, described below
	{

        PercolationStats perc2 = new PercolationStats(Integer.parseInt(args[0]),Integer.parseInt(args[1]));
        System.out.printf("mean                  = %f\n",perc2.mean());
        System.out.printf("stddev                = %f\n",perc2.stddev());
        System.out.printf("95%%confidence interval= %f,%f\n",perc2.confidenceLo(),perc2.confidenceHi());
	}
}
