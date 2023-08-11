let initFahrenheit = {js|? °F|js};

let getFahrenheit = value =>
  switch (Js.Float.fromString(value)) {
  | celsius when Js.Float.isNaN(celsius) => "error"
  | _celsius when value == "" => {js|? °F|js}
  | celsius =>
    let fahrenheit = 9.0 /. 5.0 *. celsius +. 32.0;
    string_of_float(fahrenheit) ++ {js| °F|js};
  };

[@react.component]
let make = (~value="") => {
  let (celsius, setCelsius) = React.useState(() => value);
  let (fahrenheit, setFahrenheit) = React.useState(() => getFahrenheit(value));

  <div>
    <input
      value=celsius
      onChange={evt => {
        let newValue = ReactEvent.Form.target(evt)##value |> String.trim;
        setCelsius(_ => newValue);
        setFahrenheit(_ => getFahrenheit(newValue));
      }}
    />
    {React.string({js|°C = |js})}
    <span> {React.string(fahrenheit)} </span>
  </div>;
};
