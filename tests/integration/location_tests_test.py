import unittest
import fistpp as fs


class TestLocationTests(unittest.TestCase):
    def setUp(self):
        self.equal_variances_and_sample_sizes = ([
            27.5, 21.0, 19.0, 23.6, 17.0, 17.9, 16.9, 20.1, 21.9, 22.6, 23.1,
            19.6, 19.0, 21.7, 21.4
        ], [
            27.1, 22.0, 20.8, 23.4, 23.4, 23.5, 25.8, 22.0, 24.8, 20.2, 21.9,
            22.1, 22.9, 20.5, 24.4
        ])
        self.unequal_variances_and_sample_sizes = ([
            17.2, 20.9, 22.6, 18.1, 21.7, 21.4, 23.5, 24.2, 14.7, 21.8
        ], [
            21.5, 22.8, 21.0, 23.0, 21.6, 23.6, 22.5, 20.7, 23.4, 21.8, 20.7,
            21.7, 21.5, 22.5, 23.6, 21.5, 22.5, 23.5, 21.5, 21.8
        ])

    def test_ttest(self):
        ttest_1 = fs.TTest(*self.equal_variances_and_sample_sizes)
        self.assertAlmostEqual(ttest_1.pvalue("two-sided"),
                               0.020544522734125933,
                               msg="pvalue testing")
        self.assertAlmostEqual(ttest_1.tstatistic(),
                               -2.455356398286006,
                               msg="t-statistic testing")

        ttest_2 = fs.TTest(*self.unequal_variances_and_sample_sizes)
        self.assertAlmostEqual(ttest_2.pvalue("two-sided"),
                               0.04485851653088632,
                               msg="pvalue testing")
        self.assertAlmostEqual(ttest_2.tstatistic(),
                               -2.1000496376104434,
                               msg="t-statistic testing")

    def test_welch_ttest(self):
        welch_ttest_1 = fs.WelchTTest(*self.equal_variances_and_sample_sizes)
        self.assertAlmostEqual(welch_ttest_1.pvalue("two-sided"),
                               0.021378001462866985,
                               msg="pvalue testing")
        self.assertAlmostEqual(welch_ttest_1.tstatistic(),
                               -2.455356398286006,
                               msg="t-statistic testing")

        welch_ttest_2 = fs.WelchTTest(*self.unequal_variances_and_sample_sizes)
        self.assertAlmostEqual(welch_ttest_2.pvalue("two-sided"),
                               0.14884169660532834,
                               msg="pvalue testing")
        self.assertAlmostEqual(welch_ttest_2.tstatistic(),
                               -1.5654335235985037,
                               msg="t-statistic testing")


if __name__ == '__main__':
    unittest.main()