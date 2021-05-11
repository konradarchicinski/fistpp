import unittest
import fistpp as fs


class DescriptiveStatisticsTests(unittest.TestCase):
    def setUp(self):
        self.vector1 = [
            27.5, 21.0, 19.0, 23.6, 17.0, 17.9, 16.9, 20.1, 21.9, 22.6, 23.1,
            19.6, 19.0, 21.7, 21.4
        ]
        self.vector2 = [
            27.1, 22.0, 20.8, 23.4, 23.4, 23.5, 25.8, 22.0, 24.8, 20.2, 21.9,
            22.1, 22.9, 20.5, 24.4
        ]
        self.vector3 = [
            28.2, 26.6, 20.1, 23.3, 25.2, 22.1, 17.7, 27.6, 20.6, 13.7, 23.2,
            17.5, 20.6, 18.0, 23.9, 21.6, 24.3, 20.4, 24.0, 13.2
        ]

    def test_mean(self):
        self.assertEqual(fs.mean(self.vector1), 20.819999999999997)
        self.assertEqual(fs.mean(self.vector2), 22.986666666666668)
        self.assertEqual(fs.mean(self.vector3), 21.589999999999996)

    def test_variance(self):
        self.assertEqual(fs.variance(self.vector1), 7.3429333333333355)
        self.assertEqual(fs.variance(self.vector2), 3.5584888888888900)
        self.assertEqual(fs.variance(self.vector3), 16.259900000000005)

    def test_standard_deviation(self):
        self.assertEqual(fs.standard_deviation(self.vector1),
                         2.7097847392981858)
        self.assertEqual(fs.standard_deviation(self.vector2),
                         1.8863957402647225)
        self.assertEqual(fs.standard_deviation(self.vector3),
                         4.0323566310533600)

    def test_welch_satterthwaite_equation(self):
        self.assertEqual(
            fs.welch_satterthwaite_equation(self.vector1, self.vector2),
            332.87943847853250)
        self.assertEqual(
            fs.welch_satterthwaite_equation(self.vector1, self.vector3),
            278.57195836695890)
        self.assertEqual(
            fs.welch_satterthwaite_equation(self.vector2, self.vector3),
            289.14821263364706)


if __name__ == "__main__":
    unittest.main()