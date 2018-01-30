/*
* DevKey Read example
* Basic example to read devkey string when the button is pressed.
* 
* License: MIT license
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include <iomoteClass.h>

#define Serial   SerialUSB 

char devKeyBuff[65]; // 64 bytes are used for devKey value, 1 byte for terminator char

void setup() 
{
  //  This instruction initializes the board, it's mandatory for any sketch to correctly work with the X400 Cloud Operations!
  Iomote.begin("devKey read", 1,0,0); 
  
  Serial.write("DevKey Read example\r\n");
}


void loop() 
{
  //  Check of front button to detect the push event
  if(Iomote.buttonRead() == 0)
  {
    memset(devKeyBuff, '\0', 65);

    // Read devKey from device:
    int8_t result = Iomote.devKey(devKeyBuff);
    if(result == 0)
    {
      Serial.write("devKey: ");
      Serial.println(devKeyBuff);
    }
    else
    {
      Serial.write("Unable to send data now! Result: ");
      Serial.println(result);
    }
    delay(1000);
  }
}
