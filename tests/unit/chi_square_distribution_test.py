import unittest
import stpp


class ChiSquareDistributionTests(unittest.TestCase):
    def setUp(self):
        self.chi2dist = stpp.ChiSquareDistribution()
        self.expected_values = [
            0.002001000667167574, 0.010025083647089872, 0.020100671707002250,
            0.050635615968580794, 0.102586588775100300, 0.210721031315653560,
            0.575364144903559800, 1.386294361119894300, 2.772588722239788700,
            4.605170185988072000, 5.991464547107967000, 7.377758908227861000,
            9.210340371976145000, 10.59663473309626600, 13.81551055796535400
        ]
        self.expected_mass = [
            0.4995, 0.4975, 0.4950, 0.4875, 0.4750, 0.4500, 0.3750, 0.2500,
            0.1250, 0.0500, 0.0250, 0.0125, 0.0050, 0.0025, 0.0005
        ]
        self.expected_probability = [
            0.001, 0.005, 0.010, 0.025, 0.050, 0.100, 0.250, 0.500, 0.750,
            0.900, 0.950, 0.975, 0.990, 0.995, 0.999
        ]

    def test_pdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.chi2dist.pdf(x),
                                   self.expected_mass[i],
                                   msg=f"testing pdf for {x}")

    def test_cdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.chi2dist.cdf(x),
                                   self.expected_probability[i],
                                   msg=f"testing cdf for {x}")

    def test_mean(self):
        self.assertEqual(self.chi2dist.mean(), 2.0)

    def test_variance(self):
        self.assertEqual(self.chi2dist.variance(), 4.0)


if __name__ == "__main__":
    unittest.main()