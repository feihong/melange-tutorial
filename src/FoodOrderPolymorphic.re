type sandwich =
  | Portabello
  | Ham
  | Unicorn;

type burger = {
  tomatoes: bool,
  lettuce: bool,
  bacon: int,
  onions: int,
  cheese: int,
};

let sandwichToString = sandwich => {
  let sandwich =
    switch (sandwich) {
    | Portabello => {js|🍄|js}
    | Ham => {js|🐷|js}
    | Unicorn => {js|🦄|js}
    };
  sandwich ++ " Sandwich";
};

let burgerToString = ({lettuce, tomatoes, bacon, onions, cheese}) => {
  let multi = (str, n) => Array.make(n, str) |> Js.Array.joinWith("");

  let listStr =
    [|
      lettuce ? {js|🥬|js} : "",
      tomatoes ? {js|🍅|js} : "",
      multi({js|🥓|js}, bacon),
      multi({js|🧅|js}, onions),
      multi({js|🧀|js}, cheese),
    |]
    |> Js.Array.filter(str => str != "")
    |> Js.Array.joinWith(", ");
  {js|🍔 (|js} ++ listStr ++ ")";
};

let itemToString = item =>
  switch (item) {
  | `Sandwich(sandwich) => sandwichToString(sandwich)
  | `Burger(burger) => burgerToString(burger)
  };

type standardItem = [ | `Sandwich(sandwich) | `Burger(burger)];

module LunchOrder = {
  type lunchItem = [ standardItem | `Hotdog | `Meatpie];

  [@react.component]
  let make = (~order: array(lunchItem)) =>
    <ul style={ReactDOMStyle.make(~fontSize="2em", ())}>
      {order
       |> Array.mapi((idx, item) => {
            let label =
              switch (item) {
              | `Hotdog => {js|🌭|js}
              | `Meatpie => {js|🥧|js}
              | #standardItem as item => itemToString(item)
              };
            <li key={"item-" ++ string_of_int(idx)}> {React.string(label)} </li>;
          })
       |> React.array}
    </ul>;
};

module DinnerOrder = {
  type dinnerItem = [ standardItem | `Steak | `Ramen];

  [@react.component]
  let make = (~order: array(dinnerItem)) =>
    <ul style={ReactDOMStyle.make(~fontSize="2em", ())}>
      {order
       |> Array.mapi((idx, item) => {
            let label =
              switch (item) {
              | `Steak => {js|🥩|js}
              | `Ramen => {js|🍜|js}
              | #standardItem as item => itemToString(item)
              };
            <li key={"item-" ++ string_of_int(idx)}> {React.string(label)} </li>;
          })
       |> React.array}
    </ul>;
};
