import unittest
import fistpp as fs


class ExponetialDistributionTests(unittest.TestCase):
    def setUp(self):
        self.expdist = fs.ExponentialDistribution()
        self.expected_values = [
            0.001000500333583534, 0.005012541823544286, 0.010050335853501450,
            0.025317807984289897, 0.051293294387550580, 0.105360515657826280,
            0.287682072451780900, 0.693147180559945300, 1.386294361119890600,
            2.302585092994046000, 2.995732273553990000, 3.688879454113935400,
            4.605170185988091000, 5.298317366548035000, 6.907755278982136000
        ]
        self.expected_mass = [
            0.999, 0.995, 0.990, 0.975, 0.950, 0.900, 0.750, 0.500, 0.250,
            0.100, 0.050, 0.025, 0.010, 0.005, 0.001
        ]
        self.expected_probability = [
            0.001, 0.005, 0.010, 0.025, 0.050, 0.100, 0.250, 0.500, 0.750,
            0.900, 0.950, 0.975, 0.990, 0.995, 0.999
        ]

    def test_pdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.expdist.pdf(x),
                                   self.expected_mass[i],
                                   msg=f"testing pdf for {x}")

    def test_cdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.expdist.cdf(x),
                                   self.expected_probability[i],
                                   msg=f"testing cdf for {x}")

    def test_ppf(self):
        for i, p in enumerate(self.expected_probability):
            self.assertAlmostEqual(self.expdist.ppf(p),
                                   self.expected_values[i],
                                   msg=f"testing ppf for {p}")

    def test_mean(self):
        self.assertEqual(self.expdist.mean(), 1.0)

    def test_variance(self):
        self.assertEqual(self.expdist.variance(), 1.0)


if __name__ == "__main__":
    unittest.main()