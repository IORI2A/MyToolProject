using Android.App;
using Android.OS;
using Android.Widget;
using Core;

namespace Phoneword
{
    [Activity(Label = "Phone Word", MainLauncher = true, Icon = "@drawable/icon")]
    public class MainActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            // 先调用基类的重载方法。
            base.OnCreate(savedInstanceState);

            // Resource.Layout.Main 对应到 Resource > Layout > Main.axml ，界面文件。
            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Main);

            // 绑定到界面中多个控件。
            // Get our UI controls from the loaded layout
            EditText phoneNumberText = FindViewById<EditText>(Resource.Id.PhoneNumberText);
            Button translateButton = FindViewById<Button>(Resource.Id.TranslateButton);
			TextView translatedPhoneWord = FindViewById<TextView>(Resource.Id.TranslatedPhoneWord);

			// Add code to translate number
			string translatedNumber = string.Empty;

            translateButton.Click += (sender, e) =>
            {
                // Translate user’s alphanumeric phone number to numeric
                translatedNumber = PhonewordTranslator.ToNumber(phoneNumberText.Text);
                if (string.IsNullOrWhiteSpace(translatedNumber))
                {
                    translatedPhoneWord.Text = string.Empty;
                }   
                else
                {
                    translatedPhoneWord.Text = translatedNumber;
                }
            };
        }
    }
}