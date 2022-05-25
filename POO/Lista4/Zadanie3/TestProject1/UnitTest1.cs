using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace TestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void OverCapacityTest()
        {
            int capacity = 5;
            Airport airport = new Airport(capacity);
            for (int i = 0; i < capacity; i++)
            {
                var plane = airport.AcquirePlane();
                Assert.IsNotNull(plane);
            }

            Assert.ThrowsException<ArgumentException>(
                () => airport.AcquirePlane()
            );
        }
        [TestMethod]
        public void OkCapacityTest()
        {
            int capacity = 10;
            Airport airport = new Airport(capacity);
            for (int i = 0; i < capacity; i++)
            {
                var plane = airport.AcquirePlane();
                Assert.IsNotNull(plane);
            }
        }
        [TestMethod]
        public void ReusePlaneTest()
        {
            var airport = new Airport(1);
            var plane1 = airport.AcquirePlane();
            airport.ReleasePlane(plane1);
            var plane2 = airport.AcquirePlane();

            Assert.AreEqual(plane2, plane1);
        }
        [TestMethod]
        public void TwoAirportsTest()
        {
            var airport1 = new Airport(1);
            var airport2 = new Airport(1);

            var plane1 = airport1.AcquirePlane();
            var plane2 = airport2.AcquirePlane();

            Assert.ThrowsException<ArgumentException>(
                () => {
                    airport1.ReleasePlane(plane2);
                }
            );
            Assert.ThrowsException<ArgumentException>(
                () => {
                    airport2.ReleasePlane(plane1);
                }
            );
            
        }
    }
}