import unittest
import fistpp as fs


class GammaDistributionTests(unittest.TestCase):
    def setUp(self):
        self.gammdist = fs.GammaDistribution()
        self.expected_values = [
            0.045402017769504255, 0.103494546748095220, 0.148554740253260320,
            0.242209278543967340, 0.355361510698664060, 0.531811608389610100,
            0.961278763114776800, 1.678346990016663700, 2.692634528889691000,
            3.889720169867429500, 4.743864518390583000, 5.571643390938895000,
            6.638352067993926000, 7.430129500280032000, 9.233413476451513000
        ]
        self.expected_mass = [
            0.043386768899211350, 0.093319060178248650, 0.128047177636738980,
            0.190108100671387400, 0.249079992680113400, 0.312460386727211500,
            0.367596430397839960, 0.313317691149162600, 0.182297659558751900,
            0.079548931937609980, 0.041295059303729740, 0.021195776533694740,
            0.008690817088425607, 0.004406889301068158, 0.000902280895587720
        ]
        self.expected_probability = [
            0.001, 0.005, 0.010, 0.025, 0.050, 0.100, 0.250, 0.500, 0.750,
            0.900, 0.950, 0.975, 0.990, 0.995, 0.999
        ]

    def test_pdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.gammdist.pdf(x),
                                   self.expected_mass[i],
                                   msg=f"testing pdf for {x}")

    def test_cdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.gammdist.cdf(x),
                                   self.expected_probability[i],
                                   msg=f"testing cdf for {x}")

    def test_mean(self):
        self.assertEqual(self.gammdist.mean(), 2.0)

    def test_variance(self):
        self.assertEqual(self.gammdist.variance(), 2.0)


if __name__ == "__main__":
    unittest.main()